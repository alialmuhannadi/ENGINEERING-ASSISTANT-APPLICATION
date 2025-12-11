#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lower_str(char *s) {
    for (int i = 0; s[i]; i++)
        s[i] = tolower(s[i]);
}

int color_digit(char *c) {
    lower_str(c);
    if (!strcmp(c,"black")) return 0;
    if (!strcmp(c,"brown")) return 1;
    if (!strcmp(c,"red")) return 2;
    if (!strcmp(c,"orange")) return 3;
    if (!strcmp(c,"yellow")) return 4;
    if (!strcmp(c,"green")) return 5;
    if (!strcmp(c,"blue")) return 6;
    if (!strcmp(c,"2")) return 7;
    if (!strcmp(c,"grey")) return 8;
    if (!strcmp(c,"white")) return 9;
    return -1;
}

double color_mult(char *c) {
    lower_str(c);
    if (!strcmp(c,"black")) return 1;
    if (!strcmp(c,"brown")) return 10;
    if (!strcmp(c,"red")) return 100;
    if (!strcmp(c,"orange")) return 1000;
    if (!strcmp(c,"yellow")) return 10000;
    if (!strcmp(c,"green")) return 100000;
    if (!strcmp(c,"blue")) return 1000000;
    if (!strcmp(c,"violet")) return 10000000;
    if (!strcmp(c,"grey")) return 100000000;
    if (!strcmp(c,"white")) return 1000000000;
    if (!strcmp(c,"gold")) return 0.1;
    if (!strcmp(c,"silver")) return 0.01;
    return -1;
}

double color_tol(char *c) {
    lower_str(c);
    if (!strcmp(c,"brown")) return 1;
    if (!strcmp(c,"red")) return 2;
    if (!strcmp(c,"green")) return 0.5;
    if (!strcmp(c,"blue")) return 0.25;
    if (!strcmp(c,"violet")) return 0.1;
    if (!strcmp(c,"grey")) return 0.05;
    if (!strcmp(c,"gold")) return 5;
    if (!strcmp(c,"silver")) return 10;
    return -1;
}

int color_temp(char *c) {
    lower_str(c);
    if (!strcmp(c,"brown")) return 100;
    if (!strcmp(c,"red")) return 50;
    if (!strcmp(c,"orange")) return 15;
    if (!strcmp(c,"yellow")) return 25;
    if (!strcmp(c,"blue")) return 10;
    if (!strcmp(c,"violet")) return 5;
    return -1;
}

void print_with_units(double v) {
    if (v >= 1e6) printf("%.2f MΩ\n", v/1e6);
    else if (v >= 1e3) printf("%.2f kΩ\n", v/1e3);
    else printf("%.2f Ω\n", v);
}

void decode_3_band(void) {
    char a[20], b[20], c[20];
    printf("FIRST band: "); scanf("%s", a);
    printf("SECOND band: "); scanf("%s", b);
    printf("MULTIPLIER: "); scanf("%s", c);
    int d1 = color_digit(a), d2 = color_digit(b);
    double m = color_mult(c);
    if (d1 == -1 || d2 == -1 || m == -1) {
        printf("Invalid color entered.\n\n");
        return;
    }
    double value = (d1*10 + d2) * m;
    printf("Resistance = ");
    print_with_units(value);
    printf("\n");
    return;
}

void decode_4_band(void) {
    char a[20], b[20], c[20], d[20];
    printf("FIRST band: "); scanf("%s", a);
    printf("SECOND band: "); scanf("%s", b);
    printf("MULTIPLIER: "); scanf("%s", c);
    printf("TOLERANCE: "); scanf("%s", d);
    int d1 = color_digit(a), d2 = color_digit(b);
    double m = color_mult(c), t = color_tol(d);
    if (d1 == -1 || d2 == -1 || m == -1 || t == -1) {
        printf("Invalid color entered.\n\n");
        return;
    }
    double value = (d1*10 + d2) * m;
    printf("Resistance = ");
    print_with_units(value);
    printf("Tolerance = ±%.2f%%\n", t);
    printf("\n");
    return;
}

void decode_5_band(void) {
    char a[20], b[20], c[20], d[20], e[20];
    printf("FIRST band: "); scanf("%s", a);
    printf("SECOND band: "); scanf("%s", b);
    printf("THIRD band: "); scanf("%s", c);
    printf("MULTIPLIER: "); scanf("%s", d);
    printf("TOLERANCE: "); scanf("%s", e);
    int d1 = color_digit(a), d2 = color_digit(b), d3 = color_digit(c);
    double m = color_mult(d), t = color_tol(e);
    if (d1 == -1 || d2 == -1 || d3 == -1 || m == -1 || t == -1) {
        printf("Invalid color entered.\n\n");
        return;
    }
    double value = (d1*100 + d2*10 + d3) * m;
    printf("Resistance = ");
    print_with_units(value);
    printf("Tolerance = ±%.2f%%\n", t);
    printf("\n");
    return;
}

void decode_6_band(void) {
    char a[20], b[20], c[20], d[20], e[20], f[20];
    printf("FIRST band: "); scanf("%s", a);
    printf("SECOND band: "); scanf("%s", b);
    printf("THIRD band: "); scanf("%s", c);
    printf("MULTIPLIER: "); scanf("%s", d);
    printf("TOLERANCE: "); scanf("%s", e);
    printf("TEMP COEFFICIENT: "); scanf("%s", f);
    int d1 = color_digit(a), d2 = color_digit(b), d3 = color_digit(c);
    double m = color_mult(d), t = color_tol(e);
    int tc = color_temp(f);
    if (d1 == -1 || d2 == -1 || d3 == -1 || m == -1 || t == -1 || tc == -1) {
        printf("Invalid color entered.\n\n");
        return;
    }
    double value = (d1*100 + d2*10 + d3) * m;
    printf("Resistance = ");
    print_with_units(value);
    printf("Tolerance = ±%.2f%%\n", t);
    printf("Temp Coefficient = %d ppm/K\n", tc);
    printf("\n");
    return;
}

void resistor_decoder_menu(void) {
    int choice;
    while (1) {
        printf("\n----- Resistor Decoder -----\n");
        printf("1. 3-band resistor\n");
        printf("2. 4-band resistor\n");
        printf("3. 5-band resistor\n");
        printf("4. 6-band resistor\n");
        printf("5. Back\n");
        printf("Select option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: decode_3_band(); break;
            case 2: decode_4_band(); break;
            case 3: decode_5_band(); break;
            case 4: decode_6_band(); break;
            case 5: return;
            default: printf("Invalid.\n");
        }
    }
}

void series_parallel_tool(void) {
    int count, mode;
    double r1, r2, r3;
    printf("\n--- Series/Parallel Circuit Calculator ---\n");
    printf("How many resistors? (2 or 3): ");
    scanf("%d", &count);
    printf("R1: "); scanf("%lf", &r1);
    printf("R2: "); scanf("%lf", &r2);
    if (count == 3) {
        printf("R3: "); scanf("%lf", &r3);
    }
    if (r1 <= 0 || r2 <= 0 || (count == 3 && r3 <= 0)) {
        printf("Invalid value. Must be > 0.\n\n");
        return;
    }
    printf("1 = Series, 2 = Parallel: ");
    scanf("%d", &mode);
    if (mode == 1) {
        double total = r1 + r2 + (count == 3 ? r3 : 0);
        printf("Series Total = %.2f Ω\n", total);
    } else if (mode == 2) {
        double total;
        if (count == 2) total = 1.0 / (1.0/r1 + 1.0/r2);
        else total = 1.0 / (1.0/r1 + 1.0/r2 + 1.0/r3);
        printf("Parallel Total = %.2f Ω\n", total);
    } else {
        printf("Invalid mode.\n");
    }
    printf("\n");
    return;
}

void unit_converter_tool(void) {
    int mode;
    double value;
    printf("\n--- Unit Converter ---\n");
    printf("1. Ohm → kΩ\n");
    printf("2. Ohm → MΩ\n");
    printf("3. kΩ → Ohm\n");
    printf("4. MΩ → Ohm\n");
    printf("Select: ");
    scanf("%d", &mode);
    printf("Enter value: ");
    scanf("%lf", &value);
    if (value <= 0) {
        printf("Invalid value. Must be > 0.\n\n");
        return;
    }
    switch (mode) {
        case 1: printf("%.2f Ω = %.2f kΩ\n", value, value/1000); break;
        case 2: printf("%.2f Ω = %.2f MΩ\n", value, value/1e6); break;
        case 3: printf("%.2f kΩ = %.2f Ω\n", value, value*1000); break;
        case 4: printf("%.2f MΩ = %.2f Ω\n", value, value*1e6); break;
        default: printf("Invalid option.\n");
    }
    printf("\n");
    return;
}

void statistics_tool(void) {
    int n;
    printf("\n--- Basic Statistics Tool ---\n");
    printf("How many values do you want to enter? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid amount. Must be > 0.\n\n");
        return;
    }

    double value, sum = 0, min, max;

    printf("Enter value 1: ");
    scanf("%lf", &value);

    if (value <= 0) {
        printf("Invalid value. Must be > 0.\n\n");
        return;
    }

    sum = value;
    min = value;
    max = value;

    for (int i = 2; i <= n; i++) {
        printf("Enter value %d: ", i);
        scanf("%lf", &value);

        if (value <= 0) {
            printf("Invalid value. Must be > 0.\n\n");
            return;
        }

        sum += value;
        if (value < min) min = value;
        if (value > max) max = value;
    }

    double mean = sum / n;

    printf("\n--- Results ---\n");
    printf("Mean = %.2f\n", mean);
    printf("Minimum = %.2f\n", min);
    printf("Maximum = %.2f\n", max);
    printf("\n");
}

void voltage_divider_tool(void) {
    double Vin, R1, R2, Vout;
    printf("\n--- Voltage Divider Calculator ---\n");
    printf("Enter Vin: ");
    scanf("%lf", &Vin);
    printf("Enter R1 (Ω): ");
    scanf("%lf", &R1);
    printf("Enter R2 (Ω): ");
    scanf("%lf", &R2);
    if (R1 <= 0 || R2 <= 0) {
        printf("Invalid value. Must be > 0.\n\n");
        return;
    }
    Vout = Vin * (R2 / (R1 + R2));
    printf("Output Voltage (Vout) = %.3f V\n", Vout);
    printf("\n");
    return;
}

int main(void) {
    int option;
    while (1) {
        printf("\n-----------------------------------\n");
        printf("     ENGINEERING ASSISTANT\n");
        printf("-----------------------------------\n");
        printf("1. Resistor Color Code Decoder\n");
        printf("2. Series/Parallel Circuit Calculator\n");
        printf("3. Engineering Unit Converter\n");
        printf("4. Basic Statistics Tool\n");
        printf("5. Voltage Divider Calculator\n");
        printf("6. Exit\n");
        printf("-----------------------------------\n");
        printf("Select an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1: resistor_decoder_menu(); break;
            case 2: series_parallel_tool(); break;
            case 3: unit_converter_tool(); break;
            case 4: statistics_tool(); break;
            case 5: voltage_divider_tool(); break;
            case 6:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
}
