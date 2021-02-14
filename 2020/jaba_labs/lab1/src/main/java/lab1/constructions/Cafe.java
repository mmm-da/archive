package lab1.constructions;

import lab1.InputWrappers;

import java.util.Scanner;

public class Cafe extends Building {
    private String cafeName;

    public String getCafeName() {
        return cafeName;
    }

    public void setCafeName(String cafeName) {
        this.cafeName = cafeName;
    }

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
