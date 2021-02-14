package bstu.lab3.utils;

import java.util.InputMismatchException;
import java.util.Scanner;

public class InputWrappers {

    public static Integer inputInteger(Scanner scanner, String inputMsg) {
        int value = 0;
        boolean inputLoop = true;
        // я не знаю как сделать красивее
        while (inputLoop) {
            try {
                System.out.println(inputMsg + ":");
                value = scanner.nextInt();
                inputLoop = false;
            } catch (InputMismatchException ex) {
                System.out.println("Ошибка. Повторите ввод.");
                scanner.nextLine();
            }
        }
        scanner.nextLine();
        return value;
    }

    public static Boolean inputBoolean(Scanner scanner, String inputMsg) {
        String inputString;
        String[] trueAnswers = {"y", "yes", "да", "д"};
        System.out.println(inputMsg + "(д/Н):");
        inputString = scanner.nextLine();
        for (String s : trueAnswers) {
            if (s.equals(inputString)){
                return true;
            }
        }
        return false;
    }

    public static String inputString(Scanner scanner, String inputMsg) {
        String value;
        System.out.println(inputMsg + ":");
        value = scanner.nextLine();
        return value;
    }

    public static String inputPhoneNumber(Scanner scanner) {
        String regexPattern = "^((8|\\+7)[\\- ]?)?(\\(?\\d{3}\\)?[\\- ]?)?[\\d\\- ]{7,10}$";
        while(true){
            System.out.println("Введите номер телефона:");
            String value = scanner.nextLine();
            if (value.matches(regexPattern)){
                return value;
            }
            else{
                System.out.println("Неверный формат телефона. Повторите ввод. (правильный формат 8-XXX-XXX-XX-XX)");
            }
        }
    }
}
