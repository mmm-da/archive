package lab2.constructions;

import lab2.utils.InputWrappers;
import lombok.Data;

import java.util.Scanner;

@Data
public class PrivateHouse extends House {
    private Integer privateHouseArea;

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
