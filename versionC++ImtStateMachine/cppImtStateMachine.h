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

/// @brief C#�ɂ�������Type�N���X��C++�p�ɗp��
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
	/// �X�e�[�g�}�V���N���X
	/// </summary>
	class CppImtStateMachine
	{
	public:
		/// <summary>
		/// �e���v���[�g
		/// </summary>
		/// <typeparam name="TContext">�X�e�[�g�}�V���������Ƃ��ł���R���e�L�X�g�̌^</typeparam>
		/// <typeparam name="TEvent">�X�e�[�g�}�V���֑��M����C�x���g�̌^</typeparam>
		template<typename TContext, typename TEvent>

		/// <summary>
		/// �X�e�[�g�}�V�������������Ԃ�\������X�e�[�g�N���X
		/// </summary>
		class State
		{
		public:
			// �����o�ϐ���`
			std::map<TEvent, State> transitionTable;
			CppImtStateMachine<TContext, TEvent> stateMachine;

		protected:
			/// @brief ���̃X�e�[�g����������X�e�[�g�}�V��
			CppImtStateMachine<TContext, TEvent> StateMachine => statemachine;
			/// @brief ���̃X�e�[�g����������X�e�[�g�}�V���������Ă���R���e�L�X�g
			TContext Context => stateMachine.Context;

			/// @brief �X�e�[�g�ɓ��������̏���
			virtual void enter()
			{

			}

			/// @brief �X�e�[�g���X�V����Ƃ��̏���
			virtual void update()
			{

			}

			/// @brief �X�e�[�g���o�����̏���
			virtual void exit()
			{

			}

		private:
			/// @brief �񋓑�:�X�e�[�g�}�V����update���
			enum UpdateState
			{
				IDLE,	//�������ĂȂ�
				ENTER,	//�˓�
				UPDATE,	//�X�V
				EXIT	//�E�o
			};

			//�����o�ϐ�
			UpdateState updateState;
			std::list<State> stateList;
			State currentState;
			State nextState;
			std::stack<State> stateStack;
			std::unordered_set<std::function<Type(State)>> stateFactorySet;
		};
	};

}