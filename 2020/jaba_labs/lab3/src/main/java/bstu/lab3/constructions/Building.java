package bstu.lab3.constructions;

import bstu.lab3.utils.InputWrappers;
import lombok.Data;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

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

    public void init(String dataString) {
        super.init(dataString);
        Pattern p = Pattern.compile("(\\d) '(.*)' (\\d*) '(.*)'");
        Matcher m = p.matcher(dataString);
        if (m.find()){
            this.setBuildingOwner(m.group(4));
        }else{
            throw new IllegalArgumentException();
        }
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
