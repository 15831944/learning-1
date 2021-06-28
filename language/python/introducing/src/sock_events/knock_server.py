'''
Created on Jun 23, 2021

@author:  Gabriel Dimitriu
'''
from twisted.internet import protocol, reactor

class Knock(protocol.Protocol):
    def dataReceived(self, data):
        print("Client", data.decode())
        if data.decode().startswith("Knock knock"):
            response = "Who's here?"
        else:
            response = data.decode() + " who?"
        print("Server:", response)
        self.transport.write(response.encode(encoding='utf_8', errors='strict'))

class KnockFactory(protocol.Factory):
    def buildProtocol(self, addr):
        return Knock()
    
reactor.listenTCP(8000, KnockFactory())
reactor.run()