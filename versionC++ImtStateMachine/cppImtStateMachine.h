#pragma once
#include<list>
#include<map>
#include<unordered_set>
#include<stack>
#include<functional>
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<memory>

/// @brief C#にだけあるTypeクラスをC++用に用意
class Type {
public:
	std::string name;
	std::string fullName;
	Type* baseType;
	std::vector<std::string> methodNames;

	Type(const std::string& name, const std::string& fullName, Type* base = nullptr)
		: name(name), fullName(fullName), baseType(base) {
	}

	bool IsSubclassOf(const Type* other) const {
		const Type* current = this;
		while (current) {
			if (current == other) return true;
			current = current->baseType;
		}
		return false;
	}
};
class TypeRegistry {
public:
	static TypeRegistry& Instance() {
		static TypeRegistry instance;
		return instance;
	}

	void RegisterType(const std::string& key, std::shared_ptr<Type> type) {
		types[key] = type;
	}

	std::shared_ptr<Type> GetType(const std::string& key) {
		return types[key];
	}

private:
	std::unordered_map<std::string, std::shared_ptr<Type>> types;
};


namespace cppIceMilkTeaStateMachine
{
	/// <summary>
	/// ステートマシンクラス
	/// </summary>
	class CppImtStateMachine
	{
	public:
		/// <summary>
		/// テンプレート
		/// </summary>
		/// <typeparam name="TContext">ステートマシンが持つことができるコンテキストの型</typeparam>
		/// <typeparam name="TEvent">ステートマシンへ送信するイベントの型</typeparam>
		template<typename TContext, typename TEvent>

		/// <summary>
		/// ステートマシンが処理する状態を表現するステートクラス
		/// </summary>
		class State
		{
		public:
			// メンバ変数定義
			std::map<TEvent, State> transitionTable;
			CppImtStateMachine<TContext, TEvent> stateMachine;

		protected:
			/// @brief このステートが所属するステートマシン
			CppImtStateMachine<TContext, TEvent> StateMachine => statemachine;
			/// @brief このステートが所属するステートマシンが持っているコンテキスト
			TContext Context => stateMachine.Context;

			/// @brief ステートに入った時の処理
			virtual void enter()
			{

			}

			/// @brief ステートを更新するときの処理
			virtual void update()
			{

			}

			/// @brief ステートを出た時の処理
			virtual void exit()
			{

			}

		private:
			/// @brief 列挙体:ステートマシンのupdate状態
			enum UpdateState
			{
				IDLE,	//何もしてない
				ENTER,	//突入
				UPDATE,	//更新
				EXIT	//脱出
			};

			//メンバ変数
			UpdateState updateState;
			std::list<State> stateList;
			State currentState;
			State nextState;
			std::stack<State> stateStack;
			std::unordered_set<std::function<Type(State)>> stateFactorySet;
		};
	};

}