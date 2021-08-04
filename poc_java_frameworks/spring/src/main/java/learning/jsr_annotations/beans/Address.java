package learning.jsr_annotations.beans;

import javax.inject.Named;

@Named
public class Address {
    private String city_name;
    private String street_name;
    private int build_no;

    public String getCity_name() {
        return city_name;
    }

    public void setCity_name(String city_name) {
        this.city_name = city_name;
    }

    public String getStreet_name() {
        return street_name;
    }

    public void setStreet_name(String street_name) {
        this.street_name = street_name;
    }

    public int getBuild_no() {
        return build_no;
    }

    public void setBuild_no(int build_no) {
        this.build_no = build_no;
    }

    @Override
    public String toString() {
        return city_name + "\t" + street_name + "\t" +  build_no;
    }
}
