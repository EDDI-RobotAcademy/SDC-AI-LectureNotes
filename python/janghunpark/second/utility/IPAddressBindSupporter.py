import socket
import subprocess

class IPAddressBindSupporter:
    @staticmethod
    def getIPAddress():
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

        # 엔터라인으로 인해 분리되는 객체들을 라인에 대하여
        # inet 이라는 것을 포함하고, "~~~" 이 포함되지 않은 라인인 경우에 대한 IP 주소 획득하고 break
        for line in outputString.split("\n"):
            if "inet" in line and "127.0.0.1" not in line and "172.17.0.1" not in line:
                ipAddress = line.split()[1]
                break

        return ipAddress