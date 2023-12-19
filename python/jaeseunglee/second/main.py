from server_socket.service.ServerSocketServiceImpl import ServerSocketServiceImpl

if __name__ == '__main__':
    serverSocketService = ServerSocektServiceImpl()
    serverSocketService.createServerSocket("localhost", 33333)

