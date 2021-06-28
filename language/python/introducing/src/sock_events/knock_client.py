'''
Created on Jun 23, 2021

@author:  Gabriel Dimitriu
'''
from twisted.internet import reactor, protocol

class KnockClient(protocol.Protocol):
    def connectionMade(self):
        self.transport.write("Knock knock".encode(encoding='utf_8', errors='strict'))

    def dataReceived(self, data):
        if data.decode('utf_8').startswith("Who's here?"):
            response = "Disappearing client"
            self.transport.write(response.encode(encoding='utf_8', errors='strict'))
        else:
            self.transport.loseConnection()
            reactor.stop()

class KnockFactory(protocol.ClientFactory):
    protocol = KnockClient

def main():
    f = KnockFactory()
    reactor.connectTCP("localhost", 8000, f)
    reactor.run()

if __name__ == '__main__':
    main()