#pragma once
#include <vector>

namespace lang {
	template<typename T>
	class Buffer {
		public:
		Buffer(std::vector<T> _items) : items(_items){};

		T at(){
			return items.front();
		}

		size_t left(){
			return items.size() - index;
		}

		bool stop(){
			return left() == 0;
		}
		
		bool canPeek(){
			return left() > 1;
		}

		T peek(){
			if (!canPeek())
				throw "Can't peek when size of items is < 2";
			return items.at(index + 1);
		}

		bool canPeek(size_t forward){
			if (forward == 0) return false;
			return left() > forward;
		}

		T peek(size_t forward){
			if (!canPeek(forward))
				throw "Can't peek when size of items is < forward+1";
			return items.at(index + forward);
		}

		T advance(){
			index++;
			return items.at(index - 1);
		}

		T ad(){
			return advance();
		}
		
		private:
		std::vector<T> items;
		size_t index = 0;
	};

}
