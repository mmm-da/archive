package lab1.constructions;

import lab1.InputWrappers;

import java.util.Scanner;

public class ApartmentsHouse extends House {
    private Integer apartmentsCount;

    public Integer getApartmentsCount() {
        return apartmentsCount;
    }

    public void setApartmentsCount(Integer apartmentsCount) {
        this.apartmentsCount = apartmentsCount;
    }

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
