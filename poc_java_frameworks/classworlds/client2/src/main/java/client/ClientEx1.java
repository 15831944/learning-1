package client;

import app.ISecondApi;
import service.IService;

public class ClientEx1 implements IService, ISecondApi {
    public void printme() {
        System.out.println("ClientEx1 in second client");
        implPrint();
    }

    @Override
    public void implPrint() {
        System.out.println("Second API in ClientEx1");
    }
}
