package lab1.constructions;

import lab1.InputWrappers;

import java.util.Scanner;

public class Hotel extends Building {
    private Integer hotelStarCount;

    public Integer getHotelStarCount() {
        return hotelStarCount;
    }

    public void setHotelStarCount(Integer hotelStarCount) {
        this.hotelStarCount = hotelStarCount;
    }

    public void init(Scanner scanner) {
        super.init(scanner);
        this.setHotelStarCount(
                InputWrappers.inputInteger(scanner, "Кол-во звезд отеля")
        );
    }

    @Override
    public String toString() {
        return super.toString() +
                String.format(
                        "Информация о отеле\n" +
                                "   Количество звезд отеля: %s\n",
                        this.getHotelStarCount()
                );
    }

}
