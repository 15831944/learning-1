package client;

import server.IService;

public class ClientEx1 implements IService {
    public void printme() {
        System.out.println("ClientEx1");
    }
}
