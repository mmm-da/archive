package bstu.lab3;

import bstu.lab3.constructions.*;
import bstu.lab3.utils.ConstructionInput;
import bstu.lab3.utils.InputWrappers;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Construction> array = new ArrayList<>();

        Integer constructionCount = InputWrappers.inputInteger(input, "Введите кол-во конструкций");

        for (int i = 0; i < constructionCount; i++) {
            Construction el = ConstructionInput.inputConstruction(input);
            el.init(input);
            array.add(el);
        }
        Collections.sort(array);

        for (Construction construction : array) {
            System.out.println(
                    construction.toString()
            );
        }
    }
}
