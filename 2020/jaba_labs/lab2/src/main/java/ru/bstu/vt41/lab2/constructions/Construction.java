package lab2.constructions;

import lab2.utils.InputWrappers;
import lombok.Data;

import java.util.Scanner;

@Data
public class Construction implements Comparable<Construction> {
    private String street;
    private Integer constructionCost = 0;

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
