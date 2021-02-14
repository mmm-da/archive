package lab1;

import lab1.constructions.*;

import java.util.ArrayList;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.Scanner;

public class app {
    private static Construction getConstructionType(Scanner scanner) {
        Construction construction = null;

        System.out.println("Укажите тип сооружения\n" +
                "Доступные варианты:\n" +
                "1 - здание\n" +
                "2 - отель\n" +
                "3 - кафе\n" +
                "4 - дом\n" +
                "5 - частный дом\n" +
                "6 - многоквартирный дом\n");

        int constructionType;
        boolean inputLoop = true;
        while (inputLoop) {
            System.out.println("Выберите нужный вариант:");
            try {
                constructionType = scanner.nextInt();
                inputLoop = false;
                switch (constructionType) {
                    case 1:
                        construction = new Building();
                        break;
                    case 2:
                        construction = new Hotel();
                        break;
                    case 3:
                        construction = new Cafe();
                        break;
                    case 4:
                        construction = new House();
                        break;
                    case 5:
                        construction = new PrivateHouse();
                        break;
                    case 6:
                        construction = new ApartmentsHouse();
                        break;
                    default:
                        System.out.println("Выбор некорректен. Повторите ввод.");
                        scanner.nextLine();
                        break;
                }
            } catch (InputMismatchException ex) {
                System.out.println("Выбор некорректен. Повторите ввод.");
                scanner.nextLine();
            }
        }
        scanner.nextLine();
        return construction;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Construction> array = new ArrayList<>();

        Integer constructionCount = InputWrappers.inputInteger(input, "Введите кол-во конструкций");

        for (int i = 0; i < constructionCount; i++) {
            Construction el = getConstructionType(input);
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
