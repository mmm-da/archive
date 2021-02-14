package lab1.constructions;

import lab1.InputWrappers;

import java.util.Scanner;

public class House extends Construction {
    private boolean houseHaveResidents;

    public String getHouseHaveResidents() {
        if (houseHaveResidents) {
            return "Да";
        }
        return "Нет";
    }

    public void setHouseHaveResidents(Boolean houseHaveResidents) {
        this.houseHaveResidents = houseHaveResidents;
    }

    public void init(Scanner scanner) {
        super.init(scanner);
        this.setHouseHaveResidents(
                InputWrappers.inputBoolean(scanner, "Жилой дом?"));
    }

    @Override
    public String toString() {
        return super.toString() +
                String.format(
                        "Информация о доме\n" +
                                "   Жилой дом: %s\n",
                        this.getHouseHaveResidents()
                );
    }

}
