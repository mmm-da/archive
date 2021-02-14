package lab2.constructions;

import lab2.utils.InputWrappers;
import lombok.Data;

import java.util.Scanner;

@Data
public class Apartments extends House{
    private Integer apartmentsCount;

    public void init(Scanner scanner) {
        super.init(scanner);
        this.setApartmentsCount(
                InputWrappers.inputInteger(scanner, "Количество квартир")
        );
    }

    @Override
    public String toString() {
        return super.toString() +
                String.format(
                        "Информация о многоквартирном доме\n" +
                                "   Количество квартир: %s\n",
                        this.getApartmentsCount()
                );
    }
}
