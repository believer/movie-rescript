module.exports = {
  purge: ["./src/**/*.bs.js"],
  theme: {},
  variants: {
    backgroundColor: ["responsive", "hover", "focus", "disabled"],
    textColor: ["responsive", "hover", "focus", "disabled"],
  },
  plugins: [],
  future: {
    removeDeprecatedGapUtilities: true,
  },
};
