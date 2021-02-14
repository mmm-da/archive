package lab1.constructions;

import lab1.InputWrappers;

import java.util.Scanner;

public class PrivateHouse extends House {
    private Integer privateHouseArea;

    public Integer getPrivateHouseArea() {
        return privateHouseArea;
    }

    public void setPrivateHouseArea(Integer privateHouseArea) {
        this.privateHouseArea = privateHouseArea;
    }

    @Override
    public void init(Scanner scanner) {
        super.init(scanner);
        this.setPrivateHouseArea(
                InputWrappers.inputInteger(scanner, "Площадь частного участка")
        );
    }

    @Override
    public String toString() {
        return super.toString() +
                String.format(
                        "Информация о частном доме\n" +
                                "   Площадь участка: %s\n",
                        this.getPrivateHouseArea()
                );
    }

}
