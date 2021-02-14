package lab2.constructions;

import lab2.utils.InputWrappers;
import lombok.Data;

import java.util.Scanner;

@Data
public class Hotel extends Building{
    private Integer hotelStarCount;

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
