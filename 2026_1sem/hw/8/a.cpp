template <typename First, typename Second, typename... Tail>
struct is_homogeneous  {
    const static bool value = 
        is_homogeneous <First, Second>::value and is_homogeneous <Second, Tail...>::value;
};

template <typename First, typename Second>
struct is_homogeneous <First, Second>{
    const static bool value = false;
};

template <typename First>
struct is_homogeneous <First, First>{
    const static bool value = true;
};