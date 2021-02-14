package lab1.constructions;

import lab1.InputWrappers;

import java.util.Scanner;

public class Building extends Construction {
    private String buildingOwner;

    public String getBuildingOwner() {
        return buildingOwner;
    }

    public void setBuildingOwner(String buildingOwner) {
        this.buildingOwner = buildingOwner;
    }

    @Override
    public void init(Scanner scanner) {
        super.init(scanner);
        this.setBuildingOwner(
                InputWrappers.inputString(scanner, "Владелец здания")
        );
    }

    @Override
    public String toString() {
        return super.toString() +
                String.format(
                        "Информация о здании\n" +
                                "   Владелец здания: %s\n",
                        this.getBuildingOwner()
                );
    }

}
