package lab2.constructions;

import lab2.utils.InputWrappers;
import lombok.Data;

import java.util.List;
import java.util.Scanner;

@Data
public class Building extends Construction {
    private String buildingOwner;

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
