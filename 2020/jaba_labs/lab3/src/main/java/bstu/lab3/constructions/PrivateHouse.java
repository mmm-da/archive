package bstu.lab3.constructions;

import bstu.lab3.utils.InputWrappers;
import lombok.Data;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

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

    public void init(String dataString) {
        super.init(dataString);
        Pattern p = Pattern.compile("(\\d) '(.*)' (\\d*) (\\d) '(.*)' (\\d*)'");
        Matcher m = p.matcher(dataString);
        if (m.find()){
            this.setPrivateHouseArea(
                    Integer.parseInt(m.group(6))
            );
        }else{
            throw new IllegalArgumentException();
        }
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
