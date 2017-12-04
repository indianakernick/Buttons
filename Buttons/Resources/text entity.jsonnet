{
  makePosPointsText(pos_, size_, text_):: {
    components: {
      TextRendering: {
        font: "Arial.ttf",
        size: size_,
        "hori align": "center",
        "vert align": "middle"
      },
      Transform: {
        pos: pos_
      },
      Text: text_
    }
  },
  
  makePosText(pos_, text_)::
    self.makePosPointsText(pos_, 32, text_)
}
