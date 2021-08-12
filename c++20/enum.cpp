#include <string_view>

// Bring an enum's members into scope to improve readability

enum class rgba_color_channel { red, green, blue, alpha };

std::string_view to_string(rgba_color_channel my_channel) {
    switch (my_channel) {
        using enum rgba_color_channel;
        case red:   return "red";
        case green: return "green";
        case blue:  return "blue";
        case alpha: return "alpha";
    }
    return "";
}

int main()
{
    std::string_view v = to_string(rgba_color_channel::red);
    return 0;
}
