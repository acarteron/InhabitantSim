// #ifndef PLPARSE_HH
// #define PLPARSE_HH
// #include "prologparse.hh"
//prologparse plp;
// class plparse{
// public:


// template <class T1, class T2>
// bool isIntersectLeft(T1& mA,
// 		     T2& mB) noexcept{
//  return plp.rule("intersectLeft",
// 		mA.limLeft(),
// 		mA.limDown(),
// 		mA.limUp(),
// 		mB.limLeft(),
// 		mB.limRight(),
// 		mB.limDown(),
// 		mB.limUp());
//   // return mA.limLeft() >= mB.limLeft()
//   //   && mA.limLeft() <= mB.limRight()
//   //   && mA.limDown() > mB.limUp()
//   //   && mA.limUp() < mB.limDown();
// }
// template <class T1, class T2>
// bool isIntersectRight(T1& mA, T2& mB) noexcept{
//   return plp.rule("intersectRight",
// 		mA.limRight(),
// 		mA.limDown(),
// 		mA.limUp(),
// 		mB.limLeft(),
// 		mB.limRight(),
// 		mB.limDown(),
// 		mB.limUp());
//   // return mA.limRight() >= mB.limLeft()
//   //   && mA.limRight() <= mB.limRight()
//   //   && mA.limDown() > mB.limUp()
//   //   && mA.limUp() < mB.limDown();
// }
// template <class T1, class T2>
// bool isIntersectUp(T1& mA, T2& mB) noexcept{
//   return plp.rule("intersectUp",
// 		mA.limLeft(),
// 		mA.limRight(),
// 		mA.limUp(),
// 		mB.limLeft(),
// 		mB.limRight(),
// 		mB.limDown(),
// 		mB.limUp());
//   // return mA.limRight() > mB.limLeft()
//   //   && mA.limLeft() < mB.limRight()
//   //   && mA.limUp() >= mB.limUp()
//   //   && mA.limUp() <= mB.limDown();
// }
// template <class T1, class T2>
// bool isIntersectDown(T1& mA, T2& mB) noexcept{
//   return plp.rule("intersectDown",
// 		mA.limLeft(),
// 		mA.limRight(),
// 		mA.limDown(),
// 		mB.limLeft(),
// 		mB.limRight(),
// 		mB.limDown(),
// 		mB.limUp());
//   // return mA.limRight() > mB.limLeft()
//   //   && mA.limLeft() < mB.limRight()
//   //   && mA.limDown() >= mB.limUp()
//   //   && mA.limDown() <= mB.limDown();
// }
// };
// #endif
