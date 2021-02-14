package bstu.lab3.constructions;

import bstu.lab3.utils.InputWrappers;
import lombok.Data;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

@Data
public class Hotel extends Building{
    private Integer hotelStarCount;

    public void init(Scanner scanner) {
        super.init(scanner);
        this.setHotelStarCount(
                InputWrappers.inputInteger(scanner, "Кол-во звезд отеля")
        );
    }

    public void init(String dataString) {
        super.init(dataString);
        Pattern p = Pattern.compile("(\\d) '(.*)' (\\d*) (\\d)");
        Matcher m = p.matcher(dataString);
        if (m.find()){
            this.setHotelStarCount(
                    Integer.parseInt(m.group(5))
            );
        }else{
            throw new IllegalArgumentException();
        }
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
