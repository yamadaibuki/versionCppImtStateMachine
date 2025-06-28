#pragma once

namespace cppIceMilkTeaStateMachine
{
	/// <summary>
	/// ステートマシンクラス
	/// </summary>
	class cppImtStateMachine
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
			// メンバ変数定義
			//Dictionary<TEvent, State> transitionTable;
			//ImtStateMachine<TContext, TEvent> stateMachine;
		};
	};

}