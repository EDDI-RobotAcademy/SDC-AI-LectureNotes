import socket
import subprocess

class IPAddressBindSupporter:
    @staticmethod
    def getIpAddress():
        try:
            ipAddress = socket.gethostbyname(socket.gethostname())
            return ipAddress

        except socket.gaierror:
            return None

    @staticmethod
    def getIpAddressFromGoogle():
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.connect(('8.8.8.8', 80))
                ip_address = s.getsockname()[0]
                return ip_address
        except socket.error:
            pass

        return None

    @staticmethod
    def getLocalIPAddress():
        process = subprocess.Popen(["ifconfig"], stdout=subprocess.PIPE)
        output, _ = process.communicate()
        outputString = output.decode("utf-8")

        ipAddress = None

        for line in outputString.split("\n"):
            if "inet" in line and "127.0.0.1" not in line and "172.17.0.1" not in line:
                ipAddress = line.split()[1]
                break

        return ipAddress