package lab1.constructions;

import lab1.InputWrappers;

import java.util.Scanner;

public class Construction implements Comparable<Construction> {
    private String street;
    private Integer constructionCost = 0;

    public int getConstructionCost() {
        return this.constructionCost;
    }

    public void setConstructionCost(Integer constructionCost) {
        this.constructionCost = constructionCost;
    }

    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public void init(Scanner scanner) {
        System.out.println("Введите информацию о здании.");
        this.setStreet(
                InputWrappers.inputString(scanner, "Улица")
        );
        this.setConstructionCost(
                InputWrappers.inputInteger(scanner, "Стоимость постройки")
        );
    }

    @Override
    public String toString() {
        return String.format(
                "Информация о постройке\n" +
                        "   Улица: %s\n" +
                        "   Стоимость постройки: %d\n",
                this.getStreet(),
                this.getConstructionCost()
        );
    }

    public int compareTo(Construction o) {
        Integer cost1 = this.getConstructionCost();
        Integer cost2 = o.getConstructionCost();
        if (cost1.equals(cost2)) {
            return 0;
        }
        if (cost1 > cost2) {
            return 1;
        }
        return -1;
    }
}
