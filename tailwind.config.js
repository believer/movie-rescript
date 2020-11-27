module.exports = {
  purge: ["./src/**/*.bs.js"],
  theme: {},
  variants: {
    extend: {
      backgroundColor: ["disabled"],
      textColor: ["disabled"],
    },
  },
  plugins: [],
  future: {
    removeDeprecatedGapUtilities: true,
  },
};
