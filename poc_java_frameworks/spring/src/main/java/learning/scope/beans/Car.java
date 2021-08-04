package learning.scope.beans;

import learning.lifecycle.beans.AllLifeCycle;

public class Car {
    private String color;
    private String fuelType;
    private long price;
    private AllLifeCycle data;

    public Car() {

    }

    public Car(String color, String fuelType, long price, AllLifeCycle data) {
        this.color = color;
        this.fuelType = fuelType;
        this.price = price;
        this.data = data;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setFuelType(String type) {
        this.fuelType = type;
    }

    public void setPrice(long price) {
        this.price = price;
    }

    public void setData(AllLifeCycle data) {
        this.data = data;
    }

    public void show() {
        System.out.println("Car with color=" + color + " on fuel=" + fuelType + " with price=" + price);
        if (data!=null) {
            System.out.println(data);
        }
    }
}
