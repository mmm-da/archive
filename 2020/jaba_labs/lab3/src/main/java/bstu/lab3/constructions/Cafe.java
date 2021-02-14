package bstu.lab3.constructions;

import bstu.lab3.utils.InputWrappers;
import lombok.Data;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

@Data
public class Cafe extends Building{
    private String cafeName;

    public void init(Scanner scanner) {
        super.init(scanner);
        this.setCafeName(
                InputWrappers.inputString(scanner, "Название кафе")
        );
    }

    public void init(String dataString) {
        super.init(dataString);
        Pattern p = Pattern.compile("(\\d) '(.*)' (\\d*) '(.*)' '(.*)'");
        Matcher m = p.matcher(dataString);
        if (m.find()){
            this.setCafeName(m.group(5));
        }else{
            throw new IllegalArgumentException();
        }

    }

    @Override
    public String toString() {
        return super.toString() +
                String.format(
                        "Информация о кафе\n" +
                                "   Название кафе: %s\n",
                        this.getCafeName()
                );
    }

}
