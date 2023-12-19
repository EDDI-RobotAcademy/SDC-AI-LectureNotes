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