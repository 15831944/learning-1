package client;

import app.ISecondApi;
import service.IService;

public class ClientEx2 implements IService, ISecondApi {
    public void printme() {
        System.out.println("ClientEx2");
        implPrint();
    }

    @Override
    public void implPrint() {
        System.out.println("Second API in ClientEx2");
    }
}
