#include <iostream>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <unistd.h>
using websocketpp::lib::bind;
typedef websocketpp::server<websocketpp::config::asio> server;

void on_message(server* s, websocketpp::connection_hdl hdl, server::message_ptr msg) {
    std::string message = msg->get_payload();
    s->send(hdl, message, msg->get_opcode());
//    std::cout << message << std::endl;
}

int main() {
    server print_server;

    print_server.set_message_handler(websocketpp::lib::bind(&on_message,&print_server,websocketpp::lib::placeholders::_1, websocketpp::lib::placeholders::_2));
    print_server.set_access_channels(websocketpp::log::alevel::all);
    print_server.set_error_channels(websocketpp::log::elevel::all);

    print_server.init_asio();
    print_server.listen(9002);
    print_server.start_accept();

    print_server.run();
}
