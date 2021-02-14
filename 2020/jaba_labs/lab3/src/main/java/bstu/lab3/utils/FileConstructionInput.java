package bstu.lab3.utils;

import bstu.lab3.constructions.Construction;
import bstu.lab3.enums.ConstructionTypes;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FileConstructionInput {
    public static Construction inputConstruction(String dataString){
        Pattern p = Pattern.compile("(\\d) '(.*)' (\\d*)");
        Matcher m = p.matcher(dataString);
        Integer value;
        if (m.find()){
            value = Integer.parseInt(m.group(1));
            try{
                return ConstructionTypes.valueOf(value).getСlassType().newInstance();
            }
            catch (IllegalArgumentException | InstantiationException | IllegalAccessException ex) {
                System.out.println("Введен неверный тип. Повторите ввод.");
                throw new IllegalArgumentException();
            }
        }
        System.out.println("Введен неверный тип. Повторите ввод.");
        throw new IllegalArgumentException();
    }
}
