#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

int main()
{
    // example value that demonstrates rounding for float
    float f = 123456789.123456789f;
    double d = 123456789.123456789;

    // Helper: compute number of fractional digits to produce up to
    // max_digits10 significant digits in plain (fixed) decimal notation.
    auto fractional_digits_for_fixed = [](long double value, int max_digits)->int {
        if (!std::isfinite(value)) return 0;            // inf / nan: no fractional digits
        if (value == 0.0L) return max_digits;          // zero: show max fractional digits
        long double a = std::fabs(value);
        int integer_digits = static_cast<int>(std::floor(std::log10(a))) + 1;
        int frac = max_digits - integer_digits;
        if (frac < 0) frac = 0;                        // if integer part already uses more digits
        return frac;
    };

    // For highest-accuracy, human-readable *decimal* notation (no scientific),
    // compute fractional digits so the total significant digits ≈ max_digits10.
    int frac_d = fractional_digits_for_fixed(d, std::numeric_limits<double>::max_digits10);
    int frac_f = fractional_digits_for_fixed(f, std::numeric_limits<float>::max_digits10);

    // std::cout << std::fixed << std::setprecision(frac_d) << d << '\n';
    // std::cout << std::fixed << std::setprecision(frac_f) << f << '\n';

    // Round-trip safe precision double:
    std::cout << std::setprecision(std::numeric_limits<double>::max_digits10)
              << d << "\n";
    // Round-trip safe precision float: 
    std::cout << std::setprecision(std::numeric_limits<float>::max_digits10)
              << f << "\n";

    // operator<< with std::scientific: switches the stream to scientific (exponential) notation.
    // std::setprecision(10): sets precision to 10 significant digits for scientific mode.
    // std::cout << std::scientific << std::setprecision(10);

    // // std::numeric_limits<T>::max(): static method returning the maximum finite value representable
    // // by the floating-point type T (here float). The return value is sent to the stream by operator<<.
    // std::cout << "float max:      " << std::numeric_limits<float>::max() << '\n';

    // // std::numeric_limits<T>::lowest(): returns the lowest finite value representable by T
    // // (most negative finite value). Written to the stream.
    // std::cout << "float lowest:   " << std::numeric_limits<float>::lowest() << '\n';

    // // std::numeric_limits<T>::min(): for floating types, returns the smallest positive normalized
    // // value (not the most negative). Output via operator<<.
    // std::cout << "float min (norm): " << std::numeric_limits<float>::min() << '\n';

    // // std::numeric_limits<T>::denorm_min(): smallest positive subnormal (denormalized) value.
    // std::cout << "float denorm min: " << std::numeric_limits<float>::denorm_min() << '\n';

    // // std::numeric_limits<T>::epsilon(): difference between 1 and the next representable value > 1.
    // std::cout << "float epsilon:  " << std::numeric_limits<float>::epsilon() << '\n';

    // // std::numeric_limits<T>::digits10: number of base-10 digits that can be represented without
    // // change. This is a static constexpr integer member; operator<< will format it as an integer.
    // std::cout << "float digits10: " << std::numeric_limits<float>::digits10 << '\n';

    // // Writes a single newline character to the stream.
    // std::cout << '\n';

    // // The following lines mirror the float outputs but for double. Each call above is either:
    // // - a call to operator<< on std::cout to write strings or numeric values, or
    // // - a call to a std::numeric_limits<double>::... static member/function to query type properties.
    // std::cout << "double max:     " << std::numeric_limits<double>::max() << '\n';
    // std::cout << "double lowest:  " << std::numeric_limits<double>::lowest() << '\n';
    // std::cout << "double min (norm): " << std::numeric_limits<double>::min() << '\n';
    // std::cout << "double denorm min: " << std::numeric_limits<double>::denorm_min() << '\n';
    // std::cout << "double epsilon: " << std::numeric_limits<double>::epsilon() << '\n';

    // // digits10 for double is an integer static member; written via operator<<.
    // std::cout << "double digits10:" << std::numeric_limits<double>::digits10 << '\n';

    // return 0 indicates successful program termination. No function call here; it's a return statement.
    return 0;
}