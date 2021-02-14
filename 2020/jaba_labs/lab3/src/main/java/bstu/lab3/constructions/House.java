package bstu.lab3.constructions;

import bstu.lab3.utils.InputWrappers;
import lombok.Data;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

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

    public void init(String dataString) {
        super.init(dataString);
        Pattern p = Pattern.compile("(\\d) '(.*)' (\\d*) (\\d) '(.*)'");
        Matcher m = p.matcher(dataString);
        if (m.find()){
            this.setHouseHaveResidents(m.group(4) == "1");
            this.setHouseholderPhoneNumber(m.group(5));
        }else{
            throw new IllegalArgumentException();
        }
    }

    @Override
    public String toString() {
        return super.toString() +
                "Информация о доме\n" +
                "   Жилой дом: " + this.isHouseHaveResidents() + "\n" +
                "   Телефон владельца: " + this.getHouseholderPhoneNumber() + "\n";
    }

}
