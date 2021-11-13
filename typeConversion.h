#pragma once
#include <string>

namespace typeData {
	class returnType {
	public:
		std::string value;
		std::string type;
		int size;
	};

	template<typename T>
	static inline std::string argValue(T arg) noexcept
	{
		if (std::is_same<decltype(arg), bool>::value)
			return arg ? "true" : "false";
		else
			return (std::string)arg;
	}

	template<typename T>
	static inline std::string argType(T arg) noexcept
	{
		return typeid(T).name();
	}

	template<typename T>
	static inline int argSize(T arg) noexcept
	{
		return sizeof(arg);
	}

	template<typename T>
	static inline returnType argInfo(T arg) noexcept
	{
		return { argValue(arg), argType(arg), argSize(arg) };
	}
};
