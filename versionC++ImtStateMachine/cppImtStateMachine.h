#pragma once

namespace cppIceMilkTeaStateMachine
{
	/// <summary>
	/// �X�e�[�g�}�V���N���X
	/// </summary>
	class cppImtStateMachine
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
			// �����o�ϐ���`
			//Dictionary<TEvent, State> transitionTable;
			//ImtStateMachine<TContext, TEvent> stateMachine;
		};
	};

}