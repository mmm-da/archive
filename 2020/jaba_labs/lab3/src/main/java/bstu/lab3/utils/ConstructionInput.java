package bstu.lab3.utils;

import bstu.lab3.constructions.Construction;
import bstu.lab3.enums.ConstructionTypes;

import java.util.Scanner;

public class ConstructionInput {
    public static Construction inputConstruction(Scanner input){

        while(true){
            System.out.println(ConstructionTypes.helperMessage());
            Integer value = InputWrappers.inputInteger(input,"Выберите тип: ");
            try{
                return ConstructionTypes.valueOf(value).getСlassType().newInstance();
            }
            catch (IllegalArgumentException | InstantiationException | IllegalAccessException ex) {
                System.out.println("Введен неверный тип. Повторите ввод.");
            }
        }
    }
}
