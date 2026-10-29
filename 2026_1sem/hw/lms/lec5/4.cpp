template <typename... Args>
auto avg(Args... args) {
    return (... + args) / sizeof...(args);
}