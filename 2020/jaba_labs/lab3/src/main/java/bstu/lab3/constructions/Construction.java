package bstu.lab3.constructions;

import bstu.lab3.utils.InputWrappers;
import com.sun.org.apache.xerces.internal.impl.xpath.regex.Match;
import lombok.Data;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

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

    public void init(String dataString) {
        Pattern p = Pattern.compile("(\\d) '(.*)' (\\d*)");
        Matcher m = p.matcher(dataString);
        if (m.find()){
            this.setStreet(m.group(2));
            this.setConstructionCost(
                    Integer.parseInt(m.group(3))
            );
        }else{
            throw new IllegalArgumentException();
        }
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
