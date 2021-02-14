package lab2.constructions;

import lab2.utils.InputWrappers;
import lombok.Data;

import java.util.List;
import java.util.Scanner;

@Data
public class Cafe extends Building{
    private String cafeName;

    public void init(Scanner scanner) {
        super.init(scanner);
        this.setCafeName(
                InputWrappers.inputString(scanner, "Название кафе")
        );
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
