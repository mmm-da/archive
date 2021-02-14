package lab2.utils;

import lab2.constructions.Construction;
import lab2.enums.ConstructionTypes;

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
