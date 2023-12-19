from server_socket.service.ServerSocketServiceImpl import ServerSocketServiceImpl

if __name__ == '__main__':
    serverSocketService = ServerSocketServiceImpl()
    serverSocketService.createServerSocket("localhost", 33333)
