package lab2.constructions;

import lab2.utils.InputWrappers;
import lombok.Data;

import java.util.Scanner;

@Data
public class House extends Construction {
    private boolean houseHaveResidents;
    private String householderPhoneNumber;

    @Override
    public void init(Scanner scanner) {
        super.init(scanner);
        this.setHouseHaveResidents(
                InputWrappers.inputBoolean(scanner, "Жилой дом?"));
        this.setHouseholderPhoneNumber(
                InputWrappers.inputPhoneNumber(scanner));
    }

    @Override
    public String toString() {
        return super.toString() +
                "Информация о доме\n" +
                "   Жилой дом: " + this.isHouseHaveResidents() + "\n" +
                "   Телефон владельца: " + this.getHouseholderPhoneNumber() + "\n";
    }

}
