module.exports = {
  mode: "jit",
  purge: ["./src/**/*.bs.js", "./src/**/*.css"],
  darkMode: false,
  theme: {
    extend: {},
  },
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
