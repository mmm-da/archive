package bstu.lab3.enums;

import bstu.lab3.constructions.*;
import lombok.Getter;

@Getter
public enum ConstructionTypes {
    APARTMENTS(1, Apartments.class, "Апартаменты"),
    CAFE(2, Cafe.class, "Кафе"),
    HOTEL(3, Hotel.class, "Отель"),
    PRIVATEHOUSE(4, PrivateHouse.class, "Частный дом");

    Integer type;
    String label;
    Class<? extends Construction> сlassType;

    ConstructionTypes(int i, Class<? extends Construction> aClass, String label) {
        type = i;
        this.сlassType = aClass;
        this.label = label;
    }

    public static ConstructionTypes valueOf(Integer typeValue) {
        for (ConstructionTypes constructionType : values()) {
            if (constructionType.getType().equals(typeValue)) {
                return constructionType;
            }
        }
        throw new IllegalArgumentException("Некоректный ввод.");
    }

    public static String helperMessage() {
        String msg = "Выберите нужный тип:\n";
        for (ConstructionTypes constructionType : values()) {
            msg += constructionType.type.toString() + " - " + constructionType.label + "\n";
        }
        return msg;
    }
}
